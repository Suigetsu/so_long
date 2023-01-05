#include <stdio.h>
#include <stdlib.h>

/* macro to define limits*/
#define MAX_X 4
#define MAX_Y 9

#define END_X 3
#define END_Y 8

/* define structure for one point
   with coordinate x and y */
typedef struct P{int x,y;};

/* functions to present path through matrix,
   check if next move is valid
   with backtrack technique */
void presentPath(P[],int);
int tryC(int m[][MAX_Y],int,int);
void checkPaths(int m[][MAX_Y],int,int,P[],int);

int
main()
{
/* declare start position and
   matrix we are searching paths*/
  int sX=0, sY=0,
  	m[MAX_X][MAX_Y]=
     {
      {0,0,0,1,1,1,0,0,0},
  	{1,1,0,0,0,0,0,0,0},
  	{1,0,1,0,0,1,0,1,0},
  	{0,0,1,1,0,1,1,1,0}
     };
  
  /* array that will serve to memorize the each path */
  P Path[MAX_X+MAX_Y+1];
  
  /* lets go and look for all paths */
  checkPaths(m,sX,sY,Path,0);

  return 0;
}

void 
presentPath(P   Path[MAX_X+MAX_Y+1],
			int k)
{
  for(int i=0; i<k; i++)
    printf("%d, %d",Path[i].x,Path[i].y);
  
  printf("\n\n");
}

int tryC(int m[MAX_X][MAX_Y],int x, int y)
{return ((x>=0)&&(x<MAX_X)&&(y>=0)&&(y<MAX_Y)&&m[x][y]==0);}

void 
checkPaths(int m[MAX_X][MAX_Y],
		   int c_x, int c_y,
		   P Path[MAX_X+MAX_Y+1],int l)
{
  /* will abandon path beyond wall
   and path where we hit the wall.
   your position is at the current
   x and y location*/
  if(!tryC(m,c_x,c_y)) return ;
  
  /* mark the path and memorize */
  m[c_x][c_y]=2; 
  Path[l].x=c_x;Path[l].y=c_y;
  
  /* are we at the searched position
  or check new potential candidates */
  if((c_x==END_X)&&(c_y==END_Y))
  	presentPath(Path,l+1);
  else
  {
  	/* we will try to move down, right and down-right*/
  	checkPaths(m,c_x+1,c_y+1,Path,l+1);
  	checkPaths(m,c_x+1,c_y,Path,l+1);
  	checkPaths(m,c_x,c_y+1,Path,l+1);
  }
  
  /* clear the position that has been marked */
  m[c_x][c_y]=0;
}