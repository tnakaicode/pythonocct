from setuptools import setup

setup(
    name='OCCT',
    version='7.2.0.1',
    packages=[
        'OCCT', 
        'OCCT.Boolean', 'OCCT.Exchange', 'OCCT.Topology', 'OCCT.Visualization',
        'OCCTUtils'
    ],
    package_data={
        'OCCT': ['*.so', '*.pyd', '*.dll', 'Visualization/_resources/*'],
        'OCCUtils': ['README.md', 'doc/*.*', 'examples/*.*']
    },
    author='Laughlin Research, LLC',
    author_email='info@laughlinresearch.com',
    description='Python bindings for OpenCASCADE.',
    url='https://github.com/LaughlinResearch/pyOCCT',
    license='LGPL v2.1',
    platforms=['Windows', 'Linux'],
    classifiers=['Development Status :: 3 - Alpha',
                 'Intended Audience :: Developers',
                 'Programming Language :: Python']
)
