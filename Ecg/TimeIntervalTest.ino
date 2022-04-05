int TimeIntervalTest(){
int timeVal = 0;
timeVal = map(analogRead(A1),0,1023,40,7);
return timeVal;
}
