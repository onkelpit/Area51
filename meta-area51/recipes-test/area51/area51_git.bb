SUMMARY = "Area51 – C++ demo application with ptest package"
DESCRIPTION = "A small C++ application and its bundled Boost.Test/Catch2 \
test suite, packaged for Yocto ptest integration."
HOMEPAGE = "https://github.com/onkelpit/Area51"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=00000000000000000000000000000000"

# ── Source ──────────────────────────────────────────────────────────────────
SRC_URI = "git://github.com/onkelpit/Area51.git;protocol=https;branch=main"
SRCREV = "${AUTOREV}"

PV = "1.0+git${SRCPV}"
S = "${WORKDIR}/git"

# ── Build ───────────────────────────────────────────────────────────────────
inherit cmake ptest

DEPENDS = "boost"

# Pass -DBUILD_TESTING controlled by ptest bbclass (sets it ON automatically
# when DISTRO_FEATURES contains ptest).
EXTRA_OECMAKE = "-DBUILD_TESTING=${@bb.utils.contains('DISTRO_FEATURES', 'ptest', 'ON', 'OFF', d)}"

# ── Packages ─────────────────────────────────────────────────────────────────
PACKAGES =+ "${PN}-ptest"

FILES:${PN}-ptest = "${libdir}/${PN}/ptest/"

RDEPENDS:${PN}-ptest = "\
    ${PN} \
    boost-test \
    ptest-runner \
"

# ── ptest install ────────────────────────────────────────────────────────────
# The cmake class runs `cmake --install` which already places the test
# binaries and run-ptest under ${libdir}/${PN}/ptest/.  The do_install_ptest
# hook (provided by the ptest bbclass) is therefore a no-op here, but we keep
# it explicit so it is easy to extend.
do_install_ptest() {
    # Binaries are already installed by cmake --install via the CMakeLists.txt
    # PTEST_INSTALL_DIR target.  Nothing extra needed.
    :
}
