/** @file playerinfo.cpp
 *  @brief Stores implementations of PlayerInfo class.
 *
 *  This file contains implementations of the = operator besides default codes generated by Qt.
 */

#include "playerinfo.h"

/** Copy-assignment operator
 * @param original is the pointer to be copied from.
 */
void PlayerInfo::operator=(PlayerInfo* original){
   level = original->level;
   numberOfLife = original->numberOfLife;
   numberOfSpell = original->numberOfSpell;
}

// Set default values for static member variables.
int PlayerInfo::numberOfLife = 15;
int PlayerInfo::numberOfSpell = 0;