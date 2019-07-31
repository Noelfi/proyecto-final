#ifndef funciones_h
char * extrae_password_url_encoded(char * cuerpo_http);
int buscar (char *s,char *p);
char * extrae_username_url_encoded(char * cuerpo_http);
int buscar2 (char *s,char *p);
int encontrado(int pos, FILE *fichero);
void buscar_palabra_html();
void buscar_palabra_http();
void buscar_palabra_Content_type_application();
void buscar_palabra_http1();
void buscar_palabra_Content_type_multipart();
#endif // funciones_h
