#include <string> 
#include <iostream> 
#include "dungeonexplore_ex.h" 
using namespace std; 
 
int main() { 
    int player_health = 500; 
    int gold = 0; 
    int bag_ind = 0; 
    string* bag = dungeonExplore(player_health, gold, bag_ind); 
    if (player_health >0 && bag_ind >0) { 
        cout << "Bag content: "; 
        for (int i = 0; i < bag_ind; i++)  cout << bag[i] << ", "; 
        cout << endl; 
    } 
    delete[] bag; 
} 

#include <iostream> 
#include <cstdlib>  
#include <ctime>  
#include <string> 
#include <thread> 
#include <chrono> 
#include <cmath> 
#include <vector> 
#include "dungeonexplore_ex.h" 
using namespace std; 
 
// Recursive function to explore a room 
void printMap(int** map, int size, int* curr_pos) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            if (map[i][j] == 0) cout << " "; 
            else if(i == curr_pos[0] && j == curr_pos[1]) cout << "O"; 
            else cout << "X"; 
        } 
        cout << endl; 
    } 
} 
 
void exploreRoom(int size, string* bag, int& player_health, int& gold, int* curr_pos, int* end_pos, vector<string>& ore_type, int** map, int bag_size, int& bag_ind) { 
 
    // Randomly decide what the room contains 
    map[curr_pos[0]][curr_pos[1]] = 1; 
    int event = rand() % 7 + 1; // 1 = treasure, 2 = ore, 3 = monsters, others = empty 
    if (event == 1) { 
        int ore_type_ind = rand() % ore_type.size(); 
        cout << "You found " << ore_type[ore_type_ind] << " ore!" << endl; 
        if (bag_ind > bag_size -1) cout << "Bag is full, can't take more!" << endl; 
        else { 
            bag[bag_ind] = ore_type[ore_type_ind]; 
            bag_ind += 1; 
            // cout << bag_ind << endl; 
        }     
    }  
    else if (event == 2) { 
        cout << "Oh no! You encounter monsters!" << endl; 
        player_health -= 100; 
        if (player_health > 0) { 
            if (player_health <= 500) cout << "You narrowly escape to explore further." << endl; 
        } 
        // else cout << "You are dead" << endl; 
    }  
    else if (event == 3) { 
        cout << "You found some gold!" << endl; 
        gold += 100; 
    } 
    else cout << "This room has nothing." << endl; 
     
    // Recursive case: Explore more rooms 
    if (player_health <=0) { 
        cout << "You are dead" << endl; 
        return; // base case 1 
    } 
    else if (curr_pos[0] == end_pos[0] && curr_pos[1] == end_pos[1]) { 
        cout << "You have reached the end!" << endl; 
        cout << "Leaving the dungeon" << endl; 
        return; // base case 2 
    } 
    else { 
        // options: x == 0 => can turn right or forward; y == size => can turn left 
        char dir; 
        int x = -1; 
        int y = -1; 
        while (x < 0 || x > size-1 || y < 0 || y > size-1 || map[x][y] == 1) { 
            cout << "Choose a direction (West [w], East [e], North [n], South [s]) or look at the map [m]?: "; 
            cin >> dir; 
            if (dir == 'm') { 
                printMap(map, size, curr_pos); 
                continue; 
            } 
            if (dir == 'w') {cout << "You tried moving west " << endl; x = curr_pos[0]; y = curr_pos[1]-1;} 
            else if(dir == 'e') {cout << "You tried moving east " << endl; x = curr_pos[0]; y = curr_pos[1]+1;} 
            else if (dir == 'n') {cout << "You tried moving north " << endl; x = curr_pos[0]-1; y = curr_pos[1];} 
            else if (dir == 's') {cout << "You tried moving south " << endl; x = curr_pos[0]+1; y = curr_pos[1];} 
            else {cout << "Action not possible!" << endl; continue;} 
            if (x < 0 || x > size-1 || y < 0 || y > size-1) cout << "You run into a wall! You can't go in that direction!" << endl; 
            else if (map[x][y] == 1) cout << "You already explored that room, no point in going back now!" << endl; 
        }  
        int new_pos[2] = {x,y}; 
        map[x][y] = 1; 
        exploreRoom(size, bag, player_health, gold, new_pos, end_pos, ore_type, map, bag_size, bag_ind); 
    } 
} 
 
string* dungeonExplore(int& player_health, int& gold, int& bag_ind) { 
    srand(static_cast<unsigned>(time(0)));  
    cout << "Welcome to the Dungeon Explorer!" << endl; 
    int size= rand() % 7 + 3; 
    vector<string> ore_type = {"ruby", "amethyst", "topaz"}; 
    // int player_health = 500; 
    // int gold = 0; 
    int** map = new int*[size]; 
    for (int i = 0; i < size; i++) { 
        map[i] = new int[size]; 
        for (int j = 0; j < size; j++) map[i][j] = 0; 
    } 
    int bag_size = 5; 
    string* bag = new string[bag_size]; 
    int curr_pos[2] = {rand() % size, 0}; 
    int end_pos[2] = {rand() % size, size-1}; 
     
    cout << "You enter the dungeon..." << endl; 
    exploreRoom(size, bag, player_health, gold, curr_pos, end_pos, ore_type, map, bag_size, bag_ind);  
    if (player_health > 0) { 
        cout << "You have completed your dungeon exploration. Well done!" << endl; 
        cout << "You have received " << gold << " gold." << endl; 
        cout << "You have found " << bag_ind << " pieces of ore." << endl; 
    } 
    for (int i = 0; i < size; i++) delete[] map[i]; 
    delete[] map; 
    return bag; 
} 

#ifndef _DUN_EX_H 
#define _DUN_EX_H 
#include <string> 
#include <vector> 
void printMap(int** map, int size, int* curr_pos); 
void exploreRoom(int size, std::string* bag, int& player_health, int& gold, int* curr_pos, int* end_pos, std::vector<std::string>& ore_type, 
int** map, int bag_size, int& bag_ind); 
std::string* dungeonExplore(int& player_health, int& gold, int& bag_ind); 
#endif