const int size_x = 6;
const int win_places = 4;
int i = 1;

typedef struct
{
	int score[2];
	short winner;
} Game_state;

Game_state *pState;
Game_state *pState1;
Game_state *pState2;
//int  nDummy[300];
Game_state nArray[6][5];

//Game_state State_Array[8][50];



task main()
{
	pState  = &nArray[0][0];
	pState1 = &nArray[i][0];
	pState2 = &nArray[0][i];
	Game_state &nState = nArray[0][0];

	//pState.winner = 5;
	pState->winner = 5;
	pState->score[0] = 53;
	pState->score[0] = 55;

	pState->score[0] = 56;
	pState->score[i] = 57;

	nState.score[0] = 58;
	nState.score[1] = 59;

	nState.score[1] = 60;
	nState.score[i] = 61;
	return;
}
