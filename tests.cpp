#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "caesar.h"
#include "vigenere.h"
#include "decryption.h"
// add your tests here

TEST_CASE("TASK B"){
    CHECK(shiftChar('t',1) == 'u');
    CHECK(shiftChar('a', 5) == 'f');
    CHECK(shiftChar('z', 4) == 'd');

    CHECK(shiftChar('T', 1) == 'U');
    CHECK(shiftChar('A', 5) == 'F');
    CHECK(shiftChar('Z', 4) == 'D');

    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Hello, World!", 10) == "Rovvy, Gybvn!");
    CHECK(encryptCaesar("The quick brown fox jumps over the lazy dog.", 7) == "Aol xbpjr iyvdu mve qbtwz vcly aol shgf kvn.");
    CHECK(encryptCaesar("aaa.a!aaa>A<>Q><DASDML:@.<MADSKM@LKM#LAS<>LKDLK@NKLDASM<>GF", 7) == "hhh.h!hhh>H<>X><KHZKTS:@.<THKZRT@SRT#SHZ<>SRKSR@URSKHZT<>NM");

}

TEST_CASE("TASK C")
{
    CHECK(encryptVigenere("The quick brown fox jumps over 13 lazy dogs. It also liked to eat cupcakes!", "cryptii") == "Vyc fnqkm spdpv nqo hjfxa qmcg 13 eiha umvl. Qb ccqd eqsgu rd xib elnrtsmu!");
    CHECK(encryptVigenere("aaaaaa.aaaa<aaaa.;aaaaaa.aaaaaa.aaaaaaaa!", "cryptii") == "crypti.icry<ptii.;crypti.icrypt.iicrypti!");
    CHECK(encryptVigenere("aaaaaa.aaaa<aaaa.;aaaaaa.aaaaaa.aaaaaaaa!", "abcdefghijklmnopqrstuvwxyz") == "abcdef.ghij<klmn.;opqrst.uvwxyz.abcdefgh!");
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
}

TEST_CASE("TASK D")
{
    CHECK(decryptCaesar("Bfd yt Lt!", 5) == "Way to Go!");
    CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!");
    CHECK(decryptCaesar("Aol xbpjr iyvdu mve qbtwz vcly aol shgf kvn.", 7) == "The quick brown fox jumps over the lazy dog.");
    CHECK(decryptCaesar("hhh.h!hhh>H<>X><KHZKTS:@.<THKZRT@SRT#SHZ<>SRKSR@URSKHZT<>NM", 7) == "aaa.a!aaa>A<>Q><DASDML:@.<MADSKM@LKM#LAS<>LKDLK@NKLDASM<>GF");
    CHECK(decryptVigenere("Vyc fnqkm spdpv nqo hjfxa qmcg 13 eiha umvl. Qb ccqd eqsgu rd xib elnrtsmu!","cryptii") == "The quick brown fox jumps over 13 lazy dogs. It also liked to eat cupcakes!");
    CHECK(decryptVigenere("crypti.icry<ptii.;crypti.icrypt.iicrypti!","cryptii") == "aaaaaa.aaaa<aaaa.;aaaaaa.aaaaaa.aaaaaaaa!");
    CHECK(decryptVigenere("abcdef.ghij<klmn.;opqrst.uvwxyz.abcdefgh!", "abcdefghijklmnopqrstuvwxyz") == "aaaaaa.aaaa<aaaa.;aaaaaa.aaaaaa.aaaaaaaa!");
    CHECK(decryptVigenere("Jevpq, Wyvnd!","cake") == "Hello, World!");
}