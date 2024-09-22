print("Loading diffpy.pdffit2 package")
try:
    from importlib.metadata import version
    __version__ = version("diffpy.pdffit2")
except ImportError:
    __version__ = "unknown"
