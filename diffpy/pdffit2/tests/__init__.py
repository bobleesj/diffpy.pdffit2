#!/usr/bin/env python
##############################################################################
#
# diffpy.pdffit2    by DANSE Diffraction group
#                   Simon J. L. Billinge
#                   (c) 2012 Trustees of the Columbia University
#                   in the City of New York.  All rights reserved.
#
# File coded by:    Pavol Juhas
#
# See AUTHORS.txt for a list of people who contributed.
# See LICENSE.txt for license information.
#
##############################################################################

"""Unit tests for the diffpy.pdffit2 package.
"""

# version
__id__ = '$Id$'

def test():
    '''Execute all unit tests for the diffpy.pdffit2 package.
    Return a unittest TestResult object.
    '''
    import unittest
    modulenames = '''
        diffpy.pdffit2.tests.ExceptionsTest
        diffpy.pdffit2.tests.TestPdfFit
        diffpy.pdffit2.tests.TestPhaseFractions
        diffpy.pdffit2.tests.TestShapeFactors
    '''.split()
    suite = unittest.TestSuite()
    loader = unittest.defaultTestLoader
    for mname in modulenames:
        exec ('import %s as mobj' % mname)
        suite.addTests(loader.loadTestsFromModule(mobj))
    runner = unittest.TextTestRunner()
    result = runner.run(suite)
    return result

# End of file