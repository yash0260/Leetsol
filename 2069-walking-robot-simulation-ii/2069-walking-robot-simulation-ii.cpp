class Robot {
public:
int w,h;
int x=0,y=0;
int dir=0;
vector<string>directions={"East","North","West","South"};
vector<int>dx={1,0,-1,0};
vector<int>dy={0,1,0,-1};
int perimeter;
    Robot(int width, int height) {
        w=width;
        h=height;
        perimeter=2*(w+h)-4;
    }
    
    void step(int num) {
       num%=perimeter;
       if(num==0){
        if(x==0 && y==0)dir=3;
        return ;
       } 
       while(num--){
        int nx=x+dx[dir];
        int ny=y+dy[dir];
        if(nx<0 || nx>=w ||ny<0 ||ny>=h){
            dir=(dir+1)%4;
            num++;
        }else{x=nx;
        y=ny;
        }
       }
    }
    
    vector<int> getPos() {
     return {x,y};   
    }
    
    string getDir() {
        return directions[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */