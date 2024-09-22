
import diffpy.pdffit2
from importlib.metadata import version

def test_import():
    from importlib.metadata import version
    __version__ = version("diffpy.pdffit2")

    from diffpy.pdffit2 import pdffit2_ext
    from diffpy.pdffit2.output import redirect_stdout
    from diffpy.pdffit2.pdffit import PdfFit
    from diffpy.pdffit2.pdffit2_ext import is_element

    # End of file