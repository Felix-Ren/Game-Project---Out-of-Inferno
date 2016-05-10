/** @file debug.cpp
 *  @brief Stores implementations of functions.
 *
 *  This file contains implementations of functions declared in DEBUG_H.
 */

#include "debug.h"

/** check if two QLabel items intersect with each other.
 *  @param label_1 is the first label pointer.
 *  @param label_2 is the second label pointer.
 *  @returns true is there exists a pixel in both rects.
 *  @returns false is there doesn't exist a pixel in both rects.
 * */
bool labelIntersected(QLabel* label_ptr1, QLabel* label_ptr2){
    return(label_ptr1->geometry().intersects(label_ptr2->geometry()));
}
