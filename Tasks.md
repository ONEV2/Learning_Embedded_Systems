## Task States

* ### Running :-
In a single core processor, only 1 task can be run at any given instance of time.

* ### Ready :-
Ready task are those that are able to execute, but are not currently executing because some other equal or high priority task is currently being executed[running state].

* ### Blocked :-
Task is said to be in blocked state if it waiting for a event to complete, for example if we call a vTaskDelay in a task, it will put that task in the blocked state.
Task in the blocked state, normally have a timeout period, after which the task will be timeout, and be unblocked, even if the event the task was waiting for has not occurred.
