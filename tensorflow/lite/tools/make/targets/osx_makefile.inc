# Settings for macOS.
ifeq ($(TARGET), osx)
	MACOSX_PLATFORM := $(shell xcrun --sdk macosx --show-sdk-platform-path)
		MACOSX_SYSROOT := $(shell xcrun --sdk macosx --show-sdk-path)
	OSX_SDK_VERSION := $(shell xcrun --sdk macosx --show-sdk-version)
	MIN_SDK_VERSION := 10.10
	# Override TARGET_ARCH with armv7, armv7s, arm64, i386, or x86_64.
	TARGET_ARCH := x86_64
	CXXFLAGS += -mmacosx-version-min=$(MIN_SDK_VERSION) \
		-DGEMMLOWP_ALLOW_SLOW_SCALAR_FALLBACK \
		-DTF_LITE_USE_CBLAS \
		-Wno-c++11-narrowing \
		-mno-thumb \
		-fno-exceptions \
		-isysroot \
		${MACOSX_SYSROOT} \
		-arch $(TARGET_ARCH) \
		-O3
	CFLAGS += -mmacosx-version-min=$(MIN_SDK_VERSION) \
		-mno-thumb \
		-isysroot \
		${MACOSX_SYSROOT} \
		-arch $(TARGET_ARCH) \
		-O3
	LDFLAGS := -mmacosx-version-min=${MIN_SDK_VERSION} \
		-framework Accelerate \
		-arch $(TARGET_ARCH)
endif
