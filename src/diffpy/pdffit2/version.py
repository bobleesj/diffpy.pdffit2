#!/usr/bin/env python
##############################################################################
#
# (c) 2024 The Trustees of Columbia University in the City of New York.
# All rights reserved.
#
# File coded by: Billinge Group members and community contributors.
#
# See GitHub contributions for a more detailed list of contributors.
# https://github.com/diffpy/diffpy.pdffit2/graphs/contributors
#
# See LICENSE.rst for license information.
#
##############################################################################

"""Definition of __version__."""

#  We do not use the other three variables, but can be added back if needed.
# obtain version information
from importlib.metadata import version, PackageNotFoundError

try:
    __version__ = version("diffpy.pdffit2")
except PackageNotFoundError:
    # The package is not installed (typical in editable installs) - fallback
    __version__ = "unknown"
