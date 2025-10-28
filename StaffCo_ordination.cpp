
/**
 * @file StaffCo_ordination.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-10-29
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "StaffCo_ordination.h"

// Assume all commands come from the manager for now

/**
 * @brief Construct a new StaffCo_ordination object
 */
StaffCo_ordination::StaffCo_ordination() : Nursery() {}

/**
 * @brief Send message from one staff to another based on command type
 * @param message Message to be sent
 * @param to Staff sending the message
 * @param type Type of command being sent
 */
void StaffCo_ordination::sendMessage(string message, Staff* to, string type) {
    if (to == NULL || (to->getType() != "Gardener" && to->getType() != "Sales" && to->getType() != "Admin")) return;
    cout << "Manager is asking " << to->getType() << " to: " << message << endl;

    to->receiveMessage(type);
}
