/**
 * @file teleoperation_datatypes.h
 * @author Gonna Yaswanth (yaswanth.gonna@addverb.com)
 * @brief Definitions and declarations for all the enums, data structures for teleoperation
 * @version 0.1
 * @date 2025-09-18
 *
 * @copyright Copyright (c) 2025
 *
 */

 #ifndef TELEOPERATION_DATATYPES_H
 #define TELEOPERATION_DATATYPES_H
 #include <optional>

 namespace Teleoperation
 {
    struct State
    {
       std::optional<std::vector<double>> pose;
    };

    using pose = std::vector<double>(6, 0.0);
    
 } // namespace Teleoperation
 



 
 