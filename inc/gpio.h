/*
 * Nombre del archivo: mi_archivo.c
 * Descripción: [Breve descripción del archivo]
 * Autor: Luis Gómez P.
 * Derechos de Autor: (C) 2023 [Tu nombre o el de tu organización]
 * Licencia: GNU General Public License v3.0
 *
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita
 * de COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO PARTICULAR. Ver la
 * Licencia Pública General GNU para más detalles.
 *
 * Deberías haber recibido una copia de la Licencia Pública General GNU
 * junto con este programa. Si no es así, visita <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

#ifndef GPIO_H
#define GPIO_H

/** @file  gpio.h
 ** @brief Capa de abstracción para la gestión de puertos digitales
 **/

/* === Headers files inclusions ================================================================ */
#include <stdint.h>
#include <stdbool.h>
/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

/**
 * @brief Puntero a una estructura anónima
 *        Estructura gpio_h pero no estoy definiendo cuales son los miembros.
 *        y estoy declarado un puntero a esa estructura que desconozco lo que tengo adentro
 * @return
 */

typedef struct gpio_h * gpio_t; //

/* === Public data type declarations =========================================================== */

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */

/**
 * @brief Crea una nueva instancia de GPIO y la inicializa.
 *
 * Esta función crea una nueva instancia de una estructura GPIO, asignando los valores
 * iniciales para el puerto y el pin especificados.
 *
 * @param port Número de puerto GPIO.
 * @param bit Número de pin dentro del puerto GPIO.
 * @return gpio_t Retorna un puntero a la nueva instancia de la estructura GPIO.
 */
gpio_t GpioCreate(uint8_t port, uint8_t bit);

/**
 * @brief Establece la dirección de un GPIO.
 *
 * Configura el GPIO como entrada o salida según el valor de 'output'.
 *
 * @param gpio Puntero a la instancia de GPIO.
 * @param output Si es 'true', establece el GPIO como salida. Si es 'false', como entrada.
 */
void GpioSetDirection(gpio_t gpio, bool output);

/**
 * @brief Obtiene la dirección actual de un GPIO.
 *
 * Consulta si el GPIO está configurado como entrada o salida.
 *
 * @param gpio Puntero a la instancia de GPIO.
 * @return bool Retorna 'true' si el GPIO está configurado como salida, 'false' si es entrada.
 */
bool GpioGetDirection(gpio_t gpio);

/**
 * @brief Establece el estado de un GPIO.
 *
 * Cambia el estado del GPIO (alto o bajo) si está configurado como salida.
 *
 * @param gpio Puntero a la instancia de GPIO.
 * @param state Estado a establecer. 'true' para alto, 'false' para bajo.
 */
void GpioSetState(gpio_t gpio, bool state);

/**
 * @brief Obtiene el estado actual de un GPIO.
 *
 * Consulta el estado actual del GPIO (alto o bajo) si está configurado como salida.
 *
 * @param gpio Puntero al objeto GPIO obtenido al llamar a la función GpioCreate.
 * @return bool Retorna 'true' si el estado actual es alto, 'false' si es bajo.
 */
bool GpioGetState(gpio_t gpio);

/* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* GPIO_H */
