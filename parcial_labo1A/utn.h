#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);


/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);



/** \brief imprime en pantalla el menu principal y captura la eleccion del usuario
 *
 * \return int devuelve la eleccion del usuario
 *
 */
int menu();



/** \brief imprime en pantalla el submenu de modificar y capta la eleccion del usuario
 *
 * \return int retorna la eleccion
 *
 */
int subMenu();



/** \brief imprime en pantalla el submenu de informes y capta la eleccion del usuario
 *
 * \return int
 *
 */
int menuInformes();


/** \brief valida la fecha ingresada
 *
 * \param dia int dia de la fecha
 * \param mes int mes de la fecha
 * \param anio int anio de la fecha
 * \return int retorna 1 en caso de fecha valida y 0 en caso de fecha no valida
 *
 */
int validateDate(int dia, int mes, int anio);

#endif // UTN_H_INCLUDED
