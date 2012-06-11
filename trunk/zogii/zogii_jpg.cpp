#include "zogii_jpg.h"


int zogaes_imageload_imagesizeW;
int zogaes_imageload_imagesizeH;

//设置图片输出的最大像素
void zogaes_setimage_size(unsigned  int w, unsigned int h)
{
    zogaes_imageload_imagesizeW = w;
    zogaes_imageload_imagesizeH = h;
}

//返回缩放比率 1=1/1 8=1/8
int zogaes_getimage_scale(unsigned int w, unsigned int h)
{
    int i, j, k;
    //int rval=1;

    i = w / zogaes_imageload_imagesizeW + 1;
    j = h / zogaes_imageload_imagesizeH + 1;

    k = (i > j) ? i : j;
    /*
    	while(rval<k) rval*=2;
    	return rval;
    	*/
    return k;
}

//typedef int jmp_buf[16];
struct my_error_mgr
{
    struct jpeg_error_mgr pub;	/* "public" fields */
    jmp_buf setjmp_buffer;	/* for return to caller */
};

typedef struct my_error_mgr *my_error_ptr;

METHODDEF(void)	my_error_exit (j_common_ptr cinfo)
{
    my_error_ptr myerr = (my_error_ptr) cinfo->err;
    //屏蔽此句 不弹警告
    //(*cinfo->err->output_message) (cinfo);
    longjmp(myerr->setjmp_buffer, 1);
}

//必须RGB
GLubyte *zoga_loadJPEG(wchar_t *filename, GLuint *iWidth, GLuint *iHeight)
{
    FILE *fp = NULL;
    struct my_error_mgr jerr;
    struct jpeg_decompress_struct cinfo;
    GLubyte *image_data = NULL;
    GLubyte *image_datap = NULL;

    //JSAMPROW j;
    //unsigned long int i;


    /* Open image file */
    fp = _wfopen (filename, L"rb");
    if (!fp)
    {
        fprintf(stderr, "error: couldn't open \"%s\"!\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr.pub);
    //屏蔽错误报警
    jerr.pub.error_exit = my_error_exit;

    /* Establish the setjmp return context for my_error_exit to use. */
    if (setjmp(jerr.setjmp_buffer))
    {
        jpeg_destroy_decompress(&cinfo);
        fclose(fp);
        return NULL;
    }

    /* Create and configure decompressor */
    jpeg_create_decompress (&cinfo);
    jpeg_stdio_src (&cinfo, fp);
    jpeg_read_header (&cinfo, TRUE);

    //速度优化
    cinfo.dct_method = JDCT_FASTEST;
    cinfo.two_pass_quantize = FALSE;
    cinfo.dither_mode = JDITHER_ORDERED;
    cinfo.do_fancy_upsampling = FALSE;

    //缩放比1/2 最多1/8
    cinfo.scale_num = 1;

    //缩放比
    int scale_denom = zogaes_getimage_scale(cinfo.image_width, cinfo.image_height);

    if(scale_denom > 8 )
    {
        /*
        //自写缩放
        cinfo.scale_denom=1;

        jpeg_start_decompress(&cinfo);

        printf("skk=%d,%d,s=%d,ss=%d\n",cinfo.output_width,cinfo.output_height,scale_denom,cinfo.scale_denom);

        image_data=zoga_jpg_conv_image(cinfo,cinfo.output_components, cinfo.output_width,cinfo.output_height,scale_denom);

        *iWidth= cinfo.output_width/scale_denom;
        *iHeight= cinfo.output_height/scale_denom;
        //必须
        cinfo.output_scanline = cinfo.output_height;
        */
        //自写缩放
        cinfo.scale_denom = 2;

        jpeg_start_decompress(&cinfo);
        //printf("jpg=%d,%d\n",cinfo.output_width,cinfo.output_height);
        if (3 != cinfo.output_components)
        {
            fprintf(stderr, "jpeg no num_components\n");
            jpeg_finish_decompress (&cinfo);
            jpeg_destroy_decompress (&cinfo);
            fclose (fp);
            image_data = NULL;

            return NULL;
        }

        scale_denom = zogaes_getimage_scale(cinfo.output_width, cinfo.output_height);

        //printf("skk=%d,%d,s=%d,ss=%d\n",cinfo.output_width,cinfo.output_height,scale_denom,cinfo.scale_denom);

        image_data = zoga_jpg_conv_image(&cinfo, cinfo.output_components, cinfo.output_width, cinfo.output_height, scale_denom);

        *iWidth = cinfo.output_width / scale_denom;
        *iHeight = cinfo.output_height / scale_denom;
        //必须
        cinfo.output_scanline = cinfo.output_height;

    }
    else
    {
        if(1 == scale_denom || 2 == scale_denom || 4 == scale_denom || 8 == scale_denom)
        {
            //缩放比在1/8要求内
            cinfo.scale_denom = scale_denom;

            jpeg_start_decompress(&cinfo);


            if (3 != cinfo.output_components)
            {
                fprintf(stderr, "jpeg no num_components\n");
                jpeg_finish_decompress (&cinfo);
                jpeg_destroy_decompress (&cinfo);
                fclose (fp);
                image_data = NULL;

                return NULL;
            }

            /* Initialize image's member variables */
            image_data = (GLubyte *)malloc(sizeof(GLubyte) * cinfo.output_width * cinfo.output_height * cinfo.output_components);
            image_datap = image_data;

            while (cinfo.output_scanline < cinfo.output_height)
            {
                jpeg_read_scanlines(&cinfo, &image_datap, 1);
                image_datap += cinfo.output_width * cinfo.output_components;
            }

            *iWidth = cinfo.output_width;
            *iHeight = cinfo.output_height;
        }
        else
        {
            cinfo.scale_denom = 1;
            jpeg_start_decompress(&cinfo);
            //printf("jpg=%d,%d\n",cinfo.output_width,cinfo.output_height);
            if (3 != cinfo.output_components)
            {
                fprintf(stderr, "jpeg no num_components\n");
                jpeg_finish_decompress (&cinfo);
                jpeg_destroy_decompress (&cinfo);
                fclose (fp);
                image_data = NULL;

                return NULL;
            }
            scale_denom = zogaes_getimage_scale(cinfo.output_width, cinfo.output_height);

            //printf("skk=%d,%d,s=%d,ss=%d\n",cinfo.output_width,cinfo.output_height,scale_denom,cinfo.scale_denom);

            image_data = zoga_jpg_conv_image(&cinfo, cinfo.output_components, cinfo.output_width, cinfo.output_height, scale_denom);

            *iWidth = cinfo.output_width / scale_denom;
            *iHeight = cinfo.output_height / scale_denom;
            //必须
            cinfo.output_scanline = cinfo.output_height;
        }
    }

    jpeg_finish_decompress (&cinfo);
    jpeg_destroy_decompress (&cinfo);
    fclose(fp);

    return image_data;
}

void zoga_freeImage(GLubyte *image)
{
    if(image)
        free(image);
    image = NULL;
}

//结构体必须用指针传入
GLubyte *zoga_jpg_conv_image(struct jpeg_decompress_struct *cinfo,
                             GLint num_components, GLuint src_w, GLuint src_h, int scale_denom)
{
    unsigned long int i,  m,  di, dj, sj;
    int j, n;
    int scaleS = scale_denom - 1;
    GLuint widthscale = src_w / scale_denom;
    GLuint heightscale = src_h / scale_denom;
    GLubyte *image_data = (GLubyte *)calloc(heightscale * widthscale * num_components, sizeof(GLubyte));
    GLubyte *temp_row = NULL;

    if(NULL == image_data)
    {
        fprintf(stderr, "JPG image_data error\n");
        return NULL;
    }
    temp_row = (GLubyte *)malloc(sizeof(GLubyte) * src_w * num_components);
    if(NULL == temp_row)
    {
        fprintf(stderr, "jpg temp_row error\n");
        if(image_data)
            free(image_data);
        image_data = NULL;
        return NULL;
    }

    //heightscale-1
    //倒置
    for (i = 0 ; i < heightscale; i++)
    {
        jpeg_read_scanlines(cinfo, &temp_row, 1);

        di = i * widthscale;
        for(m = 0; m < widthscale; m++)
        {
            dj = (di + m) * num_components;
            sj = m * scale_denom * num_components;

            for(n = 0; n < num_components; n++)
                image_data[dj+n] = temp_row[sj+n];

        }
        for(j = 0; j < scaleS; j++)
            jpeg_read_scanlines(cinfo, &temp_row, 1);
    }

    //要写在外头 用指针就不必写在外头了
    //cinfo->output_scanline = cinfo->output_height;
    if(temp_row)
        free(temp_row);
    temp_row = NULL;

    return image_data;

}

unsigned char *TEX64w64h = NULL;
unsigned char *TEX128w128h = NULL;
unsigned char *TEX256w256h = NULL;
unsigned char *TEX512w512h = NULL;
//最多一次载入64
#define MAX_BIGIMAGE_TEXTURE_NUM	64
GLuint zogaes_bigimage_textures[MAX_BIGIMAGE_TEXTURE_NUM];
//初始化
void zogiijpg_initJPG(void)
{
    glGenTextures(MAX_BIGIMAGE_TEXTURE_NUM, zogaes_bigimage_textures);

   TEX64w64h = (unsigned char *)calloc(64 * 64 * 3, sizeof(unsigned char));
    TEX128w128h = (unsigned char *)calloc(128 * 128 * 3, sizeof(unsigned char));
   TEX256w256h = (unsigned char *)calloc(256 * 256 * 3, sizeof(unsigned char));
  TEX512w512h = (unsigned char *)calloc(512 * 512 * 3, sizeof(unsigned char));
}

void zogiijpg_clearJPG(void)
{
    free(TEX64w64h);
    free(TEX128w128h);
    free(TEX256w256h);
    free(TEX512w512h);
}

//居中 拼凑成2	的倍数
void zogii_convWH(int srcw, int srch, unsigned char *srcdata,
                  int dstw, int dsth, unsigned char *dstdata)
{
    int startx, starty;
    int i, j;
    long int m, n;

    startx = (dstw - srcw) / 2;
    starty = (dsth - srch) / 2;

    m = 0;
    for(i = 0; i < srch; i++)
    {
        for(j = 0; j < srcw; j++)
        {
            n = ((starty + i) * dstw + (startx + j)) * 3;

            dstdata[n++] = srcdata[m++];
            dstdata[n++] = srcdata[m++];
            dstdata[n++] = srcdata[m++];
        }
    }
}

void zogiijpg_load2texJPG(int w, int h, wchar_t *fullPath, unsigned int ID)
{
    GLuint bigimage_width = 0;
    GLuint bigimage_height = 0;
    GLubyte *image_data = NULL;

    unsigned char *texdata = NULL;

    zogaes_setimage_size(w, h);
    image_data = zoga_loadJPEG(fullPath,
                               &bigimage_width, &bigimage_height);

    switch(w)
    {
    case 64:
        texdata = TEX64w64h;
        memset(texdata, 0, 64 * 64 * 3);
        break;
    case 128:
        texdata = TEX128w128h;
        memset(texdata, 0, 128 * 128 * 3);
        break;
    case 256:
        texdata = TEX256w256h;
        memset(texdata, 0, 256 * 256 * 3);
        break;
    case 512:
        texdata = TEX512w512h;
        memset(texdata, 0, 512 * 512 * 3);
        break;
    default:
        fprintf(stderr, "w,h >512\n");
        break;
    }

    if(NULL != image_data)
        zogii_convWH(bigimage_width, bigimage_height, image_data, w, h, texdata);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glBindTexture(GL_TEXTURE_2D, zogaes_bigimage_textures[ID]);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 w, h,
                 0, GL_RGB, GL_UNSIGNED_BYTE, texdata);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    zoga_freeImage(image_data);

}

void zogiijpg_drawJPG(int startx, int starty, int w, int h, unsigned int ID)
{
    float box[] =
    {
        (float)startx, (float)starty,
        (float)(startx + w), (float)starty,
        (float)startx, (float)(starty + h) ,
        (float)(startx + w), (float)(starty + h)
    };

    float texCoords[] =
    {
        0.0f, 0.0f,
        1, 0.0f,
        0.0f, 1,
        1, 1
    };

	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glBindTexture(GL_TEXTURE_2D, zogaes_bigimage_textures[ID]);

    glVertexPointer(2, GL_FLOAT, 0, box);
    glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glDisable(GL_TEXTURE_2D);
}

