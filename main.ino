#define MUTE 30
#define SOURCE_R 40
#define SOURCE_L 50
#define VOL_UP 31
#define FUNC 41
#define VOL_DW 51

const int _CableNegro = 0;
const int _CableRojo = 1;
const int _CableMarron = 2;
const int _CableAzul = 3;
const int _CableVerde = 4;
const int _CableAmarillo = 5;






void setup()
{
    pinMode(_CableNegro, INPUT_PULLUP);
    pinMode(_CableRojo, INPUT_PULLUP);
    pinMode(_CableMarron, INPUT_PULLUP);

    pinMode(_CableAzul, OUTPUT);
    pinMode(_CableVerde, OUTPUT);
    pinMode(_CableAmarillo, OUTPUT);

    Serial.begin(9600);
}

void loop()
{
    int command = getPressedButton();
    switch (command)
    {
    case MUTE:
        Serial.write("MUTE");
        break;

    case SOURCE_R:
        Serial.write("SOURCE RIGHT");
        break;

    case SOURCE_L:
        Serial.write("SOURCE LEFT");
        break;
    
    case VOL_UP:
        Serial.write("VOLUME UP");
        break;

    case VOL_DW:
        Serial.write("VOLUME DOWN");
        break;

    case FUNC:
        Serial.write("BUTTON FUNC");
        break;
    }
    

}

static int getPressedButton()
{
    for (unsigned int i = 3; i < 6; i++)
    {
        digitalWrite(i,HIGH);
        if (!digitalRead(_CableNegro))
        {
            switch (i)
            {
            case 3:
                digitalWrite(i,LOW);
                return MUTE;
                break;
            case 4:
                digitalWrite(i,LOW);
                return SOURCE_R;
                break;
            case 5:
                digitalWrite(i,LOW);
                return SOURCE_L;
                break;
            }
        }
        if (!digitalRead(_CableRojo))
        {
            switch (i)
            {
            case 3:
                digitalWrite(i,LOW);
                return VOL_UP;
                break;
            case 4:
                digitalWrite(i,LOW);
                return FUNC;
                break;
            case 5:
                digitalWrite(i,LOW);
                return VOL_DW;
                break;
            }
        }
    }
}