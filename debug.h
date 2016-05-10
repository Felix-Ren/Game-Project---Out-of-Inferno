/** @file debug.h
 *  @brief Stores helper functions.
 *
 * Stores labelIntersected function to determine if two labels are overlapped with each other.
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <QRect>
#include <QLabel>

bool labelIntersected(QLabel* label_ptr1, QLabel* label_ptr2);

//** check if two QRect items are overlapped with each other.
// *  @param rect1 is the first rect item.
// *  @param rect2 is the second rect item.
// *  @returns true is there exists a pixel in both rects.
// *  @returns false is there doesn't exist a pixel in both rects.

//*/
//bool isOverlapped(const QRect& rect1, const QRect& rect2){

//    //returns true if rect 1 contains any of rect2's corners.
//    if(rect1.contains(rect2.topLeft()) == true ||
//            rect1.contains(rect2.topRight()) == true ||
//            rect1.contains(rect2.bottomLeft()) == true ||
//            rect1.contains(rect2.bottomRight()) == true){
//        return true;
//    }
//    else{
//        return false;
//    }
//}

//** check if the center of two labels overlap.
// *  @param label_ptr1 is the first label pointer.
// *  @param label_ptr2 is the second label pointer.
// *  @returns true if centers overlap.
// *  @returns false if centers don't overlap.

//*/
//bool centerOverlapped(QLabel* label_ptr1, QLabel* label_ptr2){
//    // if if the center of two labels share same coordinates.
//    if(label_ptr1->contentsRect().center() == label_ptr2->contentsRect().center())
//        return true;
//    else
//        return false;
//}
#endif // DEBUG_H
