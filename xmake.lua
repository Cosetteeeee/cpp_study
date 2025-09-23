add_rules("mode.debug", "mode.release")

set_languages("c99", "cxx23")

-- 使用clang编译器
set_toolchains("clang", {sdkdir = "C:/Users/cosette/scoop/apps/llvm-mingw/current"})


-- 指定编译器路径
set_toolset("cc", "C:/Users/cosette/scoop/apps/llvm-mingw/current/bin/clang.exe")
set_toolset("cxx", "C:/Users/cosette/scoop/apps/llvm-mingw/current/bin/clang++.exe")
set_toolset("ld", "C:/Users/cosette/scoop/apps/llvm-mingw/current/bin/clang++.exe")
set_toolset("sh", "C:/Users/cosette/scoop/apps/llvm-mingw/current/bin/clang++.exe")

-- 配置使用LLVM-MinGW的libc++
add_cxxflags("--target=x86_64-w64-mingw32", "-stdlib=libc++")
add_shflags("--target=x86_64-w64-mingw32", "-stdlib=libc++")
add_ldflags("--target=x86_64-w64-mingw32", "-stdlib=libc++", {force = true})

-- 添加MinGW头文件路径

add_includedirs("C:/Users/cosette/scoop/apps/llvm-mingw/current/include")

-- 添加库搜索路径
add_linkdirs("C:/Users/cosette/scoop/apps/llvm-mingw/current/lib")
add_linkdirs("C:/Users/cosette/scoop/apps/llvm-mingw/current/x86_64-w64-mingw32/lib")

-- 运行时环境
add_runenvs("PATH", "C:/Users/cosette/scoop/apps/llvm-mingw/current/bin")
add_runenvs("PATH", "C:/Users/cosette/scoop/apps/llvm-mingw/current/x86_64-w64-mingw32/bin")

target("addressbook")
    set_kind("binary")

    add_files("addressbook/*.cpp")
    add_files("addressbook/libs/*.cpp")
    add_headerfiles("addressbook/include/*.hpp")
    add_includedirs("C:/Users/cosette/scoop/apps/llvm-mingw/current/include/c++/v1")
target("c")
    set_kind("binary")

    add_files("c/*.c")
    add_files("c/libs/*.c")
    add_headerfiles("c/include/*.h")
