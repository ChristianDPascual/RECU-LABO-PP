#ifndef VALIDACION_H_INCLUDED
#define VALIDACION_H_INCLUDED
/**
 * @fn int mostrarMenu()
 * @brief Muestra el menu de opciones
 *
 * @return retorna la opcion elegida
 */
int mostrarMenu();

/**
 * @fn int validarPalabra(char[])
 * @brief Valida que sea una palabra el dato ingresado por el usuario
 *
 * @param el dato que ingreso el usuario
 * @return retorna TRUE si es correto o FALSE en caso que ocurra un mal ingreso de dato
 */
int validarPalabra(char[]);
/**
 * @fn int DarRespuesta()
 * @brief Pregunta (si/no) al usuario para ciertas acciones
 *
 * @return retorna TRUE en caso de si o FALSE en caso de no
 */
int DarRespuesta();
/**
 * @fn int validarNumeroEntero(char[])
 * @brief Valida que sea un numero entero el dato ingresado por el usuario
 *
 * @param el dato que ingreso el usuario
 * @return retorna TRUE si es correto o FALSE en caso que ocurra un mal ingreso de dato
 */
int validarNumeroEntero(char[]);
/**
 * @fn int validarNumeroFlotante(char[])
 * @brief Valida que sea un numero flotante el dato ingresado por el usuario
 *
 * @param el dato que ingreso el usuario
 * @return retorna TRUE si es correto o FALSE en caso que ocurra un mal ingreso de dato
 */
int validarNumeroFlotante(char[]);
/**
 * @fn int validarDNI(char[])
 * @brief Valida que el dni ingresado sea correcto
 *
 * @param retorna 0 en caso que sea exitoso y -1 en caso de error
 * @return
 */
int validarDNI(char[]);

#endif // VALIDACION_H_INCLUDED
