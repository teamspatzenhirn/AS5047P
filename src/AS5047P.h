#ifndef AS5047P_h
#define AS5047P_h

#include <inttypes.h>

#ifdef ARDUINO_ARCH_SAMD
#include <string>
#endif

#include "types/AS5047P_Types.h"
#include "spi/AS5047P_SPI.h"


#define AS5047P_INFO_STRING_BUFFER_SIZE 350

/**
 * @class AS5047P
 * @brief The main class for the AS5047P sensor.
 */
class AS5047P {
    
    public:

        // Constructors ------------------------------------------------

        /**
         * Constructor.
         * @param chipSelectPinNo The pin number of the chip select pin (default: 9);
         * @param spiSpeed The spi bus speed (default: 8000000, on Feather M0 tested up to 32000000)
         */
        AS5047P(uint8_t chipSelectPinNo = 9, uint32_t spiSpeed = 100000);

        // -------------------------------------------------------------

        // Init --------------------------------------------------------

        /**
         * Initializes the sensor object & tests the connection. Must be calles once befor unsing the sensor object.
         * @return True on success, else false
         */
        bool initSPI();

        // -------------------------------------------------------------

        // Util --------------------------------------------------------

        /**
         * Checks the AS5047P sensors error registers for communication errors and clears this register.
         * @param errorOut A pointer to an AS5047P_types::ERROR_t error object to store the received information.
         * @return True if no errors were found, else false.
         */
        bool checkForComErrorF(AS5047P_types::ERROR_t *errorOut);

        /**
         * Checks the AS5047P sensors error registers for sensor errors.
         * @param errorOut A pointer to an AS5047P_types::ERROR_t error object to store the received information.
         * @return True if no errors were found, else false.
         */
        bool checkForSensorErrorF(AS5047P_types::ERROR_t *errorOut);

        /**
         * Verifies the content of a given register.
         * @param regAddress The address of the register to verify.
         * @param expectedData The expected data in the register (The correct parity bit must be set!).
         * @return True if the register contains the expected data, else false.
         */
        bool verifyWittenRegF(uint16_t regAddress, uint16_t expectedData);


        #ifdef ARDUINO_ARCH_SAMD
        /**
         * Reads all status information from the AS5047P sensor and returns them as a string.
         * @return A std::string with all status information.
         */
        std::string readStatusAsStdString();
        #endif

        /**
         * Reads all status information from the AS5047P sensor and returns them as a string.
         * @return A string (Arduino String) with all status information.
         */
        String readStatusAsArduinoString();


        // -------------------------------------------------------------

        // Read High-Level ---------------------------------------------

        /**
         * Read the current magnitude value.
         * @return The current magnitude value.
         */
        uint16_t readMagnitude();
        
        /**
         * Read the current magnitude value.
         * @return The current magnitude value.
         */
        uint16_t readMagnitude(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true);

        /**
         * Read the current raw angle value.
         * @param withDAEC Flag to select if the value with or without dynamic angle error correction should be returned.
         * @return The current raw angle value.
         */
        uint16_t readAngleRaw(bool withDAEC = true);
        
        /**
         * Read the current raw angle value.
         * @param withDAEC Flag to select if the value with or without dynamic angle error correction should be returned.
         * @return The current raw angle value.
         */
        uint16_t readAngleRaw(AS5047P_types::ERROR_t *errorOut, bool withDAEC = true, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true);

        /**
         * Read the current angle value in degree value.
         * @param withDAEC Flag to select if the value with or without dynamic angle error correction should be returned.
         * @return The current angle value in degree value.
         */
        float readAngleDegree(bool withDAEC = true);
        
        /**
         * Read the current angle value in degree value.
         * @param withDAEC Flag to select if the value with or without dynamic angle error correction should be returned.
         * @return The current angle value in degree value.
         */
        float readAngleDegree(AS5047P_types::ERROR_t *errorOut, bool withDAEC = true, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true);

        // -------------------------------------------------------------

        // Read Volatile Registers -------------------------------------

        /**
         * Read the ERRFL register.
         * @return The contet of the ERRFL register.
         */
        auto read_ERRFL() -> AS5047P_types::ERRFL_t;
        
        /**
         * Read the ERRFL register.
         * @return The contet of the ERRFL register.
         */
        auto read_ERRFL(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::ERRFL_t;

        /**
         * Read the PROG register.
         * @return The contet of the PROG register.
         */
        auto read_PROG() -> AS5047P_types::PROG_t;
        
        /**
         * Read the PROG register.
         * @return The contet of the PROG register.
         */
        auto read_PROG(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::PROG_t;

        /**
         * Read the DIAAGC register.
         * @return The contet of the DIAAGC register.
         */
        auto read_DIAAGC() -> AS5047P_types::DIAAGC_t;
        
        /**
         * Read the DIAAGC register.
         * @return The contet of the DIAAGC register.
         */
        auto read_DIAAGC(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::DIAAGC_t;

        /**
         * Read the MAG register.
         * @return The contet of the MAG register.
         */
        auto read_MAG() -> AS5047P_types::MAG_t;
        
        /**
         * Read the MAG register.
         * @return The contet of the MAG register.
         */
        auto read_MAG(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::MAG_t;

        /**
         * Read the ANGLEUNC register.
         * @return The contet of the ANGLEUNC register.
         */
        auto read_ANGLEUNC() -> AS5047P_types::ANGLEUNC_t;
        
        /**
         * Read the ANGLEUNC register.
         * @return The contet of the ANGLEUNC register.
         */
        auto read_ANGLEUNC(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::ANGLEUNC_t;

        /**
         * Read the ANGLECOM register.
         * @return The contet of the ANGLECOM register.
         */
        auto read_ANGLECOM() -> AS5047P_types::ANGLECOM_t;
        
        /**
         * Read the ANGLECOM register.
         * @return The contet of the ANGLECOM register.
         */
        auto read_ANGLECOM(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::ANGLECOM_t;

        // -------------------------------------------------------------

        // Write Volatile Registers ------------------------------------

        /**
         * Write into the PROG register.
         * @param regDat The new contet of the PROG register.
         * @return True if no error occured, else false.
         */            
        bool write_PROG(const AS5047P_types::PROG_t *regData);

        /**
         * Write into the PROG register.
         * @param regDat The new contet of the PROG register.
         * @return True if no error occured, else false.
         */ 
        bool write_PROG(const AS5047P_types::PROG_t *regData, AS5047P_types::ERROR_t *errorOut, bool checkForComError = true, bool verifyWittenReg = true);

        // -------------------------------------------------------------

        // Read Non-Volatile Registers ---------------------------------
        
        /**
         * Read the ZPOSM register.
         * @return The contet of the ZPOSM register.
         */
        auto read_ZPOSM() -> AS5047P_types::ZPOSM_t;
        
        /**
         * Read the ZPOSM register.
         * @return The contet of the ZPOSM register.
         */
        auto read_ZPOSM(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::ZPOSM_t;

        /**
         * Read the ZPOSL register.
         * @return The contet of the ZPOSL register.
         */ 
        auto read_ZPOSL() -> AS5047P_types::ZPOSL_t;
        
        /**
         * Read the ZPOSL register.
         * @return The contet of the ZPOSL register.
         */
        auto read_ZPOSL(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::ZPOSL_t;

        /**
         * Read the SETTINGS1 register.
         * @return The contet of the SETTINGS1 register.
         */
        auto read_SETTINGS1() -> AS5047P_types::SETTINGS1_t;
        
        /**
         * Read the SETTINGS1 register.
         * @return The contet of the SETTINGS1 register.
         */
        auto read_SETTINGS1(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::SETTINGS1_t;

        /**
         * Read the SETTINGS2 register.
         * @return The contet of the SETTINGS2 register.
         */
        auto read_SETTINGS2() -> AS5047P_types::SETTINGS2_t;
        
        /**
         * Read the SETTINGS2 register.
         * @return The contet of the SETTINGS2 register.
         */
        auto read_SETTINGS2(AS5047P_types::ERROR_t *errorOut, bool verifyParity = true, bool checkForComError = true, bool checkForSensorError = true) -> AS5047P_types::SETTINGS2_t;

        // -------------------------------------------------------------

        // Write Non-Volatile Registers --------------------------------

        /**
         * Write into the ZPOSM register.
         * @param regDat The new contet of the ZPOSM register.
         * @return True if no error occured, else false.
         */
        bool write_ZPOSM(const AS5047P_types::ZPOSM_t *regData);
        
        /**
         * Write into the ZPOSM register.
         * @param regDat The new contet of the ZPOSM register.
         */
        bool write_ZPOSM(const AS5047P_types::ZPOSM_t *regData, AS5047P_types::ERROR_t *errorOut, bool checkForComError = true, bool verifyWittenReg = true);

        /**
         * Write into the ZPOSL register.
         * @param regDat The new contet of the ZPOSL register.
         * @return True if no error occured, else false.
         */
        bool write_ZPOSL(const AS5047P_types::ZPOSL_t *regData);
        
        /**
         * Write into the ZPOSL register.
         * @param regDat The new contet of the ZPOSL register.
         * @return True if no error occured, else false.
         */
        bool write_ZPOSL(const AS5047P_types::ZPOSL_t *regData, AS5047P_types::ERROR_t *errorOut, bool checkForComError = true, bool verifyWittenReg = true);

        /**
         * Write into the SETTINGS1 register.
         * @param regDat The new contet of the SETTINGS1 register.
         * @return True if no error occured, else false.
         */
        bool write_SETTINGS1(const AS5047P_types::SETTINGS1_t *regData);
        
        /**
         * Write into the SETTINGS1 register.
         * @param regDat The new contet of the SETTINGS1 register.
         * @return True if no error occured, else false.
         */
        bool write_SETTINGS1(const AS5047P_types::SETTINGS1_t *regData, AS5047P_types::ERROR_t *errorOut, bool checkForComError = true, bool verifyWittenReg = true);

        /**
         * Write into the ETTINGS2 register.
         * @param regDat The new contet of the ETTINGS2 register.
         * @return True if no error occured, else false.
         */
        bool write_SETTINGS2(const AS5047P_types::SETTINGS2_t *regData);
        
        /**
         * Write into the ETTINGS2 register.
         * @param regDat The new contet of the ETTINGS2 register.
         * @return True if no error occured, else false.
         */
        bool write_SETTINGS2(const AS5047P_types::SETTINGS2_t *regData, AS5047P_types::ERROR_t *errorOut, bool checkForComError = true, bool verifyWittenReg = true);

        // -------------------------------------------------------------

    private:

        AS5047P_ComBackend::AS5047P_SPI __spiInterface;       ///< The instance of the spi interface for the sensor communication.

};

#endif // AS5047P_h