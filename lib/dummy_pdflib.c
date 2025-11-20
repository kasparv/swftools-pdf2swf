/* dummy_pdflib.c
 *
 * Provides a stub get_internal() for builds without PDFlib.
 * This prevents link errors when building flanter21's swftools fork
 * in configurations where PDFlib is not available.
 *
 * pdf2swf does NOT use PDFlib — only SWF→PDF output code needs it.
 *
 * Author: Kaspar V.
 * Date: 2025
 */

#include <stddef.h>

void *get_internal(void *dev)
{
    (void)dev;
    /* Returning NULL disables PDFlib-dependent features gracefully */
    return NULL;
}
