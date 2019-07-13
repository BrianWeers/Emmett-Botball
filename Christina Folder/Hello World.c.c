#include <stdio.h>
#include <kipr/botball.h>

boolean cameraOpen = false;
int motorInch = 200


int main()
{
    //orchestratate the project
    startup();
    clearPath();
    getBotguy();
    Exit;
    
    
}

void getBotGuy(){
    raiseArm();
    openPincer();
    rollForward(2);//roll forward 2 inches
    closePincer();
    rollReverse(18);
}

void clearPath(){

}

void startup(){
    enable_servos();
    shut_downin(119);
    wait_for_light(0);
}

//roll robot forward in inches
void rollForward(int dist){
    useMotor(0,1,750);
    useMotor(3,1,750);
    int totalTime(motorInch * dist);
    msleep(totalTime);
}

void rollReverse(int dist){
    useMotor(0,1,750);
    useMotor(3,-1,750);
    int totalTime(motorInch * dist);
    msleep(totalTime);
}
void useMotor(int port,int direction,int speed){ 
    mav(port,(speed*direction));
}



void doCam() {
    initializeCamera();
    cameraUpdate();
}


void initializeCamera(){
    if( !cameraOpen == true)
        {
            camera_open_black();
            cameraOpen=true;            
        }
}
void openPincer(){
    doservo(0,0);
}
void closePincer(){
    doservo(0,2047);
}
void raiseArm(){
    doservo(1,0);
}
void lowerArm(){P
    doservo(1,2047)
}

void doServo(int port, int position){
    setServoPosition(port,position);
}