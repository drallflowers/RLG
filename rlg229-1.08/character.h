#ifndef CHARACTER_H
# define CHARACTER_H

# include <stdint.h>

# include "dims.h"
#include "dice.h"
#include "descriptions.h"
#include "dungeon.h"

typedef struct dungeon dungeon_t;
typedef struct npc npc_t;
typedef struct pc pc_t;

typedef struct character {
  
  pair_t position;
  uint32_t speed;
  uint32_t next_turn;
  uint32_t alive;
  /* The priority queue is not stable.  It's nice to have a record of *
   * how many monsters have been created, and this sequence number    *
   * serves that purpose, but more importantly, prioritizing lower    *
   * sequence numbers ahead of higher ones guarantees that turn order *
   * is fair.  PC get sequence number zero, and a global sequence,    *
   * stored in the dungeon, is incremented each time a NPC is         *
   * created and copied here then.                                    */
  uint32_t sequence_number;
  npc_t *npc;
  pc_t *pc;
  int32_t color;
  int32_t hit;  
  const char* name;
  const char* description;
  char symbol;  
  uint32_t abilities;
  uint32_t hitpoints;
  const dice_t* damage;  
} character_t;

int32_t compare_characters_by_next_turn(const void *character1,
                                        const void *character2);
uint32_t can_see(dungeon_t *d, character_t *voyeur, character_t *exhibitionist);
void character_delete(void *c);

#endif
