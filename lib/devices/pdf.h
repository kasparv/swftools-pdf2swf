/* pdf.h
   Header file for pdf.c

   Part of the swftools package.

   Copyright (c) 2009 Matthias Kramm <kramm@quiss.org> 
   ...
*/

#ifndef __gfxdevice_pdf_h__
#define __gfxdevice_pdf_h__

/* ---- change here: remove <pdflib.h> and forward-declare PDF ---- */
/* Original flanter21 version had:  #include <pdflib.h>  */
/* We avoid the external dependency by just forward-declaring the type. */
typedef struct PDF_s PDF;

#include "../gfxdevice.h"
#include "../gfxtools.h"

#ifdef __cplusplus
extern "C" {
#endif

// What's a secret between friends, eh? ;)
typedef struct _internal {
    PDF* p;
    
    char config_addblankpages;
    double config_xpad;
    double config_ypad;
    int config_maxdpi;
    int config_mindpi;

    int width,height;
    int num_pages;

    char*tempfile;
    char*page_opts;
    double lastx,lasty;
    gfxfontlist_t*fontlist;

    char has_matrix;
    double m00, m01, m10, m11;
} internal_t;

internal_t* get_internal(gfxdevice_t*dev);
void pdf_drawchars(gfxdevice_t*dev, gfxfont_t*font, int* chars, int len,
                   gfxcolor_t*color, gfxmatrix_t*matrixes);
void gfxdevice_pdf_init(gfxdevice_t*dev);

#ifdef __cplusplus
}
#endif

#endif //__gfxdevice_pdf_h__
