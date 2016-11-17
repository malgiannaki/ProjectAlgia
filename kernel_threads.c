
#include "tinyos.h"
#include "kernel_sched.h"
#include "kernel_proc.h"

/** 
  @brief Create a new thread in the current process.
  */
Tid_t CreateThread(Task task, int argl, void* args)
{



  PTCB* ptcb;

 ptcb->thread_task=task;
 ptcb->argl=argl;
 ptcb->args=args;


ptcb->thread_pointer= spawn_thread(CURPROC, start_thread());
 
	return (Tid_t) ptcb->thread_pointer;
}


void start_thread()
{
  PTCB* ptcb;

  int exitval;

  Task call =  ptcb->thread_task;
  int argl = ptcb->argl;
  void* args = ptcb->args;

  exitval = call(argl,args);
  Exit(exitval);
}

/**
  @brief Return the Tid of the current thread.
 */
Tid_t ThreadSelf()
{
	return (Tid_t) CURTHREAD;
}

/**
  @brief Join the given thread.
  */
int ThreadJoin(Tid_t tid, int* exitval)
{


	return -1;
}

/**
  @brief Detach the given thread.
  */
int ThreadDetach(Tid_t tid)
{
	return -1;
}

/**
  @brief Terminate the current thread.
  */
void ThreadExit(int exitval)
{


}


/**
  @brief Awaken the thread, if it is sleeping.

  This call will set the interrupt flag of the
  thread.

  */
int ThreadInterrupt(Tid_t tid)
{
	return -1;
}


/**
  @brief Return the interrupt flag of the 
  current thread.
  */
int ThreadIsInterrupted()
{
	return 0;
}

/**
  @brief Clear the interrupt flag of the
  current thread.
  */
void ThreadClearInterrupt()
{

}

