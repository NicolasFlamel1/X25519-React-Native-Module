cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

add_library(X25519React
            SHARED
            ../cpp/x25519-react.cpp
            cpp-adapter.cpp
            ../X25519-WASM-Wrapper-master/crypto_hash_sha512.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/base.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_0.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_1.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_add.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_copy.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_cswap.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_frombytes.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_invert.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_mul.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_mul121666.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_sq.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_sub.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/fe_tobytes.c
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10/scalarmult.c
)

include_directories(
            ../cpp
            ../
            ../X25519-WASM-Wrapper-master
            ../supercop-20220213/crypto_scalarmult/curve25519/ref10
)

add_definitions(-D CRYPTO_NAMESPACE\\\(x\\\)=x)
