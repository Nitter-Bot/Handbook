int dx[] = {1,1,0,-1,-1,-1,0,1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

int floodfill(int x,int y,char color1,char color2){
	if(grid[x][y] == "outside")return 0;
	if(grid[x][y] != color1)return 0;
	int ans = 1;
	grid[x][y] = color2;
	for(int d=0;d<8;d++)ans += floodfill(x+dx[d],y+dy[d],color1,colr2);
	return ans;
}
