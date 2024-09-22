

def test_import():
    from diffpy.pdffit2 import pdffit2_ext
    print(pdffit2_ext)
    assert pdffit2_ext is not None
    # from diffpy.pdffit2 import pdffit2
    