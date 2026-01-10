class Solution {
public:
    bool isRobotBounded(string instructions) {
        // clockwise direction as N, E, S, W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x=0, y=0;
        int dir =0; // North ,1->East , 2->South , 3->West

        for(char c : instructions){
            if(c =='G'){
                x += dx[dir];
                y += dy[dir];

            }else if(c == 'L'){
                dir = (dir+3)%4;
            }else{
                dir = (dir+1)%4;
            }
        }

        return (x==0 && y==0) || dir != 0;
    }
};