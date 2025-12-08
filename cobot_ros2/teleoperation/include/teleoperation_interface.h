/**
 * @file cartesian_impedance_controller.h
 * @author Gonna Yaswanth (yaswanth.gonna@addverb.com)
 * @brief Teleoperation Interface: interface for teleoperation
 * @version 0.1
 * @date 2025-07-12
 *
 * @copyright Copyright (c) 2025
 *
 */


#ifndef TELEOPERATION_INTERFACE_H_
#define TELEOPERATION_INTERFACE_H_

#include <memory>
#include <string>
#include <vector>

class TeleoperationInterface
{

public:
    virtual ~TeleoperationInterface() = default;
    virtual bool connect() = 0;
    virtual bool start() = 0;
    virtual bool getTarget(std::vector<double> &current_pose, std::vector<double> &target) = 0;
    

}