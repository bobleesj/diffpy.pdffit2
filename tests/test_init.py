

def test_import():
    from diffpy.pdffit2 import pdffit2_ext
    print(pdffit2_ext)
    assert pdffit2_ext is not None
    # from diffpy.pdffit2 import pdffit2
    """PDFfit2 - real space structure refinement program."""

    # package version
    from diffpy.pdffit2.output import redirect_stdout
    from diffpy.pdffit2.version import __version__, __date__
    from diffpy.pdffit2.pdffit import PdfFit
    from diffpy.pdffit2.pdffit2_ext import is_element

    # End of file