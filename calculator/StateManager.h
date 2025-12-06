//
// Created by Dave Smith on 11/5/25.
//

#ifndef STATEMANAGER_H
#define STATEMANAGER_H


/// Check the value of a given
///
/// Toggles the value of a given state
///
/// enable a state
///
/// disable a state
///
/// set a state to a particular boolean
#include <map>
enum StateType
{
    CLUCKED, HIDDEN, HOVERED, ENABLED, BLINKING,CLICKED,

    ///add any new above this line
    LAST_STATE
};
class StateManager {
    std::map<StateType, bool> _states;

public:
    StateManager();
    bool getState(StateType state) const;
    void toggleState(StateType state);
    void enableState(StateType state);
    void disableState(StateType state);
    void setState(StateType state, bool status);
};



#endif //STATEMANAGER_H
