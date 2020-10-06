message("-- External Project: fmt")
include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY  https://github.com/fmtlib/fmt.git
    GIT_TAG         7.0.3
)

FetchContent_MakeAvailable(fmt)

set_target_properties("fmt" PROPERTIES FOLDER "thirdparty/fmt")