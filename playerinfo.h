/** @file playerinfo.h
 *  @brief Stores the playerInfo class.
 *
 * Stores information of the character and related functionalities.
 */

#ifndef PLAYERINFO_H
#define PLAYERINFO_H

#include <QString>
#include <iostream>
#include <string>

using std::cout;
using std::string;

/**@class playerInfo
 * @brief The playerInfo class with two int variable and a string object.
 *
 * Stores current level, the number of lives and spells the player has and the current level.
 */
class PlayerInfo
{
public:
    /** Default constructor */
    PlayerInfo():level(""){}

    /** Construct a PlayerInfor object with given level name, remained life, and remained spell.
     * @param levelName is the name of the level
     * @param life is the number of remaining life
     * @param spell is the number of remaining spell
     */
    PlayerInfo(QString levelName):level(levelName){}

    /** Decrease number of lives and check if the player is still alive.
     * @return true if the player is still alive.
     * @returns false if the player just died.
     */
    bool decreaseLife(){
        // check if the player dies after decreasing life.
        if(numberOfLife < 1 || numberOfLife == 1){
            return false;
        } else {
            numberOfLife -= 1;
//            cout << "one life deducted!";
            return true;
        }
    }

    /** Use one spell if have at least one left.
     *  @returns true if the player successfully used a spell.
     *  @returns false if the player does not have spells left.
    */
    bool useSpell(){

        // check if has spell left.
        if(numberOfSpell < 1) return false;
        else {
            numberOfSpell -= 1;
            return true;
        }
    }

    /** Set the name of the level
     * @param levelName is the new name.
     */
    void setLevel(const QString levelName){
        level = levelName;
    }

    /** Set the number of life of the character.
     * @param l is the new number of life.
     */
    void setLife(int l){
        numberOfLife = l;
    }

    void operator=(PlayerInfo*);

private:
    QString level;
    static int numberOfLife;
    static int numberOfSpell;

    friend class Stage; // B5
    friend class B4;
    friend class B3;
    friend class MainWindow;
};

#endif // PLAYERINFO_H
