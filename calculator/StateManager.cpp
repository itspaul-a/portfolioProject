//
// Created by Dave Smith on 11/5/25.
//

#include "StateManager.h"

StateManager::StateManager()
{
    for (int i=0; i < LAST_STATE; i++)
        _states[static_cast<StateType>(i)] = false;
}

bool StateManager::getState(StateType state) const
{
    return _states.at(state);
}

void StateManager::toggleState(StateType state)
{
    setState(state, !getState(state));
}

void StateManager::enableState(StateType state)
{
    _states[state] = true;
}

void StateManager::disableState(StateType state)
{
    _states[state] = false;
}

void StateManager::setState(StateType state, bool status)
{
    _states[state] = status;
}
