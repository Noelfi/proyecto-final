#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LIMITE 5000
#define MAX 50
#include "minunit.h"
#include "../funciones.h"
#define MINUNIT_EPSILON 1E-3



char *p1="pass";
char *p2="pass";
char *p3="hola";
char *p4="hola";
char *p5="ho";
char *p6="ho";
char *p7="la";
char *p8="la";
char *p9="bye";
char *p10="bye";
char *p11="by";
char *p12="by";
char *p13="be";
char *p14="be";
char *p15="ye";
char *p16="ye";
char *p17="qw";
char *p18="qw";
char *p19="cv";
char *p20="cv";






MU_TEST(test_funcion_buscar) {
	mu_check(buscar(p1,p2)==-1);
}
MU_TEST(test_funcion_buscar1) {
	mu_check(buscar(p3,p4)==-1);
}
MU_TEST(test_funcion_buscar2) {
	mu_check(buscar(p5,p6)==-1);
}
MU_TEST(test_funcion_buscar3) {
	mu_check(buscar(p7,p8)==-1);
}
MU_TEST(test_funcion_buscar4) {
	mu_check(buscar(p9,p10)==-1);
}
MU_TEST(test_funcion_buscar5) {
	mu_check(buscar(p11,p12)==-1);
}
MU_TEST(test_funcion_buscar6) {
	mu_check(buscar(p13,p14)==-1);
}
MU_TEST(test_funcion_buscar7) {
	mu_check(buscar(p15,p16)==-1);
}
MU_TEST(test_funcion_buscar8) {
	mu_check(buscar(p17,p18)==-1);
}
MU_TEST(test_funcion_buscar9) {
	mu_check(buscar(p19,p20)==-1);
}

//MU_TEST(test_funcion_simbo_especial) {
//	mu_check( simbo_especial(contr)== 0);
//}
//MU_TEST(test_funcion_minuscula1) {
//    mu_assert_int_eq(minuscula(contrase), 1);
//
//}
//MU_TEST(test_funcion_simbo_especial1) {
//	mu_check( simbo_especial(contrase)== 1);
//}

MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(test_funcion_buscar);
    MU_RUN_TEST(test_funcion_buscar1);
    MU_RUN_TEST(test_funcion_buscar2);
    MU_RUN_TEST(test_funcion_buscar3);
    MU_RUN_TEST(test_funcion_buscar4);
    MU_RUN_TEST(test_funcion_buscar5);
    MU_RUN_TEST(test_funcion_buscar6);
    MU_RUN_TEST(test_funcion_buscar7);
    MU_RUN_TEST(test_funcion_buscar8);
    MU_RUN_TEST(test_funcion_buscar9);

//    MU_RUN_TEST(test_funcion_simbo_especial);
//    MU_RUN_TEST(test_funcion_minuscula1);
//    MU_RUN_TEST(test_funcion_simbo_especial1);

}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

//mu_assert_double_eq
//mu_assert_int_eq
