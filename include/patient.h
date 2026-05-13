/******************************************************************************
 * Project: Hospital Patient Triage & Bed Allocator
 * File: patient.h
 * Group: 20
 * Members: Ahsan Shafqat and Abdul Aziz Irzam
 * Roll No.: 24F-0630 and 24F-0694
 * Date: 2026-05-08
 ******************************************************************************/
#ifndef PATIENT_H
#define PATIENT_H

#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* Patient record passed via IPC */
typedef struct {
  int patient_id;
  char name[64];
  int age;
  int severity;   /* 1 -10 raw severity from triage */
  int priority;   /* 1 -5 computed triage priority */
  int care_units; /* memory units required */
  time_t arrival_time;

  /* Additional fields for simulator and management */
  char symptoms[256];
  pid_t simulator_pid;
  int assigned_bed; /* -1 if not yet assigned */
} PatientRecord;

/* Helper to convert priority to ward string */
static inline const char *priority_ward(int priority) {
  if (priority <= 2)
    return "ICU";
  if (priority == 3)
    return "Isolation";
  return "General";
}

#endif /* PATIENT_H */
