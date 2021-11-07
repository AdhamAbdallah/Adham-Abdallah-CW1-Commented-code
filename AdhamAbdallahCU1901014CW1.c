char uart_rd;  // if data is ready for reading
void main() {     //main function
     int Z;    //create variable z of type integer
     ANSELA = 0xFF;     //set port A to analog 
     ANSELB = 0 ;          //set port B to digital 
     ANSELC = 0 ;          //set port C to digital 
  ANSELD = 0  ;          //set port D to digital 
     UART1_Init(9600); // initialized UART module at baud rate 9600
     Delay_ms(100);  // delay 100 milliseconds 
     TRISA = 0xFF; // port A is set to be an input 
     TRISB = 0; // port B is set to be an Output 
     TRISC = 0; //port C is set to be an Output 
     TRISD = 0; //port D is set to be an Output 

UART1_Write_Text("begin"); // display (begin) in the UART terminal
UART1_Write(13); //backslash
UART1_Write(10); //space

while(1){ //open while loop
if (UART1_Data_Ready()){  // if the data is received
Z = ADC_Read(1); //read received data from pin Ra1/ the analog values from the LDR are converted into digital values and stored in variable z 

  if (Z >2000)            //condition if value of z. the number is determined through many tests
  {
UART1_Write_Text(" LDR is sensing ");                 //if z is greater than 2000 print on the UART terminal that it is sensing light

Delay_ms(500);                     //delay of 500 milliseconds
PORTD =0xFF ;          // set all pins in port d to 1 (meaning all led’s in port d will light up)
}
Else                 //second condition
    {
    UART1_Write_Text(" Not sensing light ");                       // if z is less than 2000 print on the UART terminal that it is not sensing light

    PORTD = 0x00;                      //set all pins in port d to 0 (meaning all led’s in port d will turn off)
    Delay_ms(500);                                //delay of 500 milliseconds
    }
  }
}
}
