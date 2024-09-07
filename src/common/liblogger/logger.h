/// @author [jag1799]
/// @date [2024]
/// @file logger
/// @{

#ifndef LOGGER_H_
#define LOGGER_H_

namespace libdsa
{
    namespace common
    {
        /// @brief Set of types to define what log messages get printed out at runtime.
        enum LogLevel : unsigned int
        {
            /// @brief Standard information that will always print regardless of log level.
            LOG_INFO = 0,

            /// @brief Prints additional information to assist in debugging errors.
            ///
            /// @note Setting this will print ALL message types including these.
            LOG_DEBUG,

            /// @brief Prints message that a minor runtime issue occurred but can be ignored.
            LOG_WARNING,

            /// @brief Prints a message that something has gone wrong, but the program still works.
            LOG_CRITICAL,

            /// @brief Print a message that something has gone wrong and the program crashes.
            ///
            /// @note This will always print regardless of log level if an error occurs.
            LOG_ERROR,
        };

        class Logger
        {
            public:
                Logger() = default;

                void log(const char* log, const enum LogLevel level);
        };

        void libdsa::common::Logger::log(const char* log, const enum LogLevel level)
        {
            switch(level)
            {
                case 0:
                    // This will always print.
                    std::printf("INFO::%s\n", log);
                    break;
                case 1:
                    #ifdef DEBUG
                        // Print only if DEBUG level is set.
                        std::printf("DEBUG::%s\n", log);
                    #endif // DEBUG
                    break;
                case 2:
                    #ifdef WARNING
                        // Print only if WARNING or higher is set
                        std::printf("WARNING::%s\n", log);
                    #endif // WARNING
                    break;
                case 3:
                    #ifdef CRITICAL
                        // Print only if CRITICAL or higher is set.
                        std::printf("CRITICAL::%s\n", log);
                    #endif // CRITICAL
                    break;
                case 4:
                    // Always print an error when it happens.
                    std::printf("ERROR::%s\n", log);
                    break;
            };
        }
    } // namespace common
} // namespace libdsa

#endif // LOGGER_H_

/// @}