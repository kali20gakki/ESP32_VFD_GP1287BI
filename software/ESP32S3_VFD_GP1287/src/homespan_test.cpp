// /* HomeSpan Table Lamp Example */

// #include "HomeSpan.h" // include the HomeSpan library

// //// Define the TableLamp Service ////

// struct TableLamp : Service::LightBulb
// {

//   int lampPin;                   // store the pin number connected to a hypothetical relay that turns the Table Lamp on/off
//   SpanCharacteristic *lampPower; // store a reference to the On Characteristic

//   TableLamp(int lampPin) : Service::LightBulb()
//   { // constructor() method for TableLamp defined with one parameter.  Note we also call the constructor() method for the LightBulb Service.

//     lampPower = new Characteristic::On(); // instantiate the On Characteristic and save it as lampPower
//     this->lampPin = lampPin;              // save the pin number for the hypothetical relay
//     pinMode(lampPin, OUTPUT);             // configure the pin as an output using the standard Arduino pinMode function

//   } // end constructor()

//   boolean update()
//   { // update() method

//     digitalWrite(lampPin, lampPower->getNewVal()); // use standard Arduino digitalWrite function to change the ledPin to either high or low based on the value requested by HomeKit

//     return (true); // return true to let HomeKit (and the Home App Client) know the update was successful

//   } // end update()
// };

// //// INITIALIZE HOMESPAN AND CREATE THE HAP ACCESSORY ATTRIBUTE DATABASE ////

// const char* paircode = "13466009";
// char* gen_qrcode_p;

// void setup()
// {

//   Serial.begin(115200); // start the Serial interface

//   homeSpan.begin(); // initialize HomeSpan
//   gen_qrcode_p = homeSpan.setPairingCodeAndGenQRcode(paircode);

//   if(gen_qrcode_p != nullptr){
//     Serial.print("Gen QRCode: ");
//     Serial.println(gen_qrcode_p);
//   } else {
//     Serial.println("Gen QRCode error");
//   }

//   new SpanAccessory(); // Table Lamp Accessory

//   new Service::AccessoryInformation(); // HAP requires every Accessory to implement an AccessoryInformation Service
//   new Characteristic::Identify();      // HAP requires the Accessory Information Service to include the Identify Characteristic

//   new Characteristic::Manufacturer("HomeSpan"); // Manufacturer of the Accessory (arbitrary text string, and can be the same for every Accessory)
//   new Characteristic::SerialNumber("17511520");  // Serial Number of the Accessory (arbitrary text string, and can be the same for every Accessory)
//   new Characteristic::Model("120-Volt Lamp");   // Model of the Accessory (arbitrary text string, and can be the same for every Accessory)
//   new Characteristic::FirmwareRevision("0.9");  // Firmware of the Accessory (arbitrary text string, and can be the same for every Accessory)

//   new TableLamp(45); // instantiate the TableLamp Service (defined below) with lampPin set to 17

// } // end of setup()

// //// RUN HOMESPAN ////

// void loop()
// {

//   homeSpan.poll();
// } // end of loop()