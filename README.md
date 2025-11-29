# Microfinance-Loan-Repayment-Tracker-EMI-Planner.

Project 38 : Microfinance Loan Repayment Tracker & EMI Planner.

Real-world context: Microfinance institutions track many small loans, repayment schedules, delinquencies, and interest accrual. 

Problem description (detailed): 

Develop a system that: 
Stores borrower records and loan contracts (principal, rate, tenure, EMI schedule, outstanding balance). 
Generates EMI schedules using amortization formula, accepts repayments (partial/full), updates balances, computes penalties for overdue payments, and recalculates remaining EMIs. 
Supports portfolio reports: total outstanding, delinquency rate, borrower ranking by risk score computed from repayment history. 
Use structures for borrower/loan, functions for amortization and penalty computation, arrays for multiple loans, pointers for dynamic portfolio expansion, and file I/O to persist loan books. 
Provide dashboard summaries (text) and per-borrower repayment history. 
Syllabus topics applied: Problem solving, arithmetic & floating operations, decision making, loops, arrays, functions, structures, pointers, dynamic memory, file I/O. 

CO mapping: 

CO1 : design repayment & penalty flowcharts; 

CO2 : implement EMI math and validation; 

CO3 : use arrays/functions for portfolio analytics; 

CO4 : use pointers/dynamic memory for loan book growth; 

CO5 : design a modular microfinance management solution.

_____________________________________________________________________________________________________________________________________________________________________________________________________________________

Flowcharts --> (CO1)-

Here are the pseudo-codes that show the repayment and penalty logic for the Microfinance Loan Tracker.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

1. Flowchart — EMI Calculation.
        ┌──────────────────────────┐
        │      Start               │
        └───────────┬──────────────┘
                    │
                    ▼
   
         ┌────────────────────────┐
         │ Input P, R, N          │
         │ P = Principal          │
         │ R = Monthly Rate       │
         │ N = Months             │
         └───────────┬────────────┘
                     │
                     ▼
   
        ┌──────────────────────────┐
        │ Compute EMI using        │
        │ EMI = P*R*(1+R)^N        │
        │       /((1+R)^N - 1)     │
        └───────────┬──────────────┘
                    │
                    ▼
   
        ┌──────────────────────────┐
        │ Print EMI                │
        └───────────┬──────────────┘
                    │
                    ▼
   
        ┌──────────────────────────┐
        │          End             │
        └──────────────────────────┘

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

2. Flowchart — Repayment Processing (Full / Partial / Extra Payment).

        ┌────────────────┬
        │    Start       │
        └───────┬────────┘
                ▼
    ┌─────────────────────────┐
    │ Input EMI, outstanding, │
    │ amount_paid             │
    └──────────┬──────────────┘
               ▼
    ┌──────────────────────────┐
    │ Is amount_paid == EMI ?  │
    └───────┬──────────────┬───┘
            │ Yes          │ No
            ▼              ▼
 ┌────────────────┐    ┌─────────────────────────┐
 │ Full EMI paid  │    │ Is amount_paid > EMI ?  │
 │ outstanding-=EMI│   └─────────┬───────────────┘
 └───────┬─────────┘             │ Yes
         │                       ▼
         │                  ┌──────────────────────────┐
         │                  │ Extra amount + EMI       │
         │                  │ outstanding-=amount_paid │
         │                  └───────────┬──────────────┘
         │                              │
         │ No                           ▼
         ▼                   ┌────────────────────────┐
 ┌────────────────────┐      │ Partial Payment        │
 │ amount_paid < EMI  │      │ remaining = EMI - paid │
 │ outstanding-=paid  │      │ Print remaining amount │
 └──────────┬─────────┘      └─────┬──────────────────┘
            │                      │
            ▼                      ▼
      ┌──────────────────────────────┐
      │ Print Updated Outstanding    │
      └───────────┬──────────────────┘
                  ▼
        ┌──────────────────────────┐
        │           End            │
        └──────────────────────────┘


--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

3. Flowchart — Penalty Calculation for Late Payment.

        ┌───────────────┐
        │    Start      │
        └──────┬────────┘
               ▼
     ┌──────────────────────────┐
     │ Input days_late          │
     │ Input penalty_rate/day   │
     └──────────┬───────────────┘
                ▼
      ┌─────────────────────────┐
      │ penalty = days * rate   │
      └──────────┬──────────────┘
                 ▼
      ┌─────────────────────────┐
      │ Print penalty amount    │
      └──────────┬──────────────┘
                 ▼
     ┌────────────────────────┐
     │          End           │
     └────────────────────────┘

   -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

   4. Flowchart — Delinquency Calculation (Portfolio Risk).

        ┌───────────────┐
        │    Start      │
        └───────────────┘
                │
                ▼
      ┌────────────────────┐
      │ Input n borrowers  │
      └────────┬───────────┘
               │
               ▼
   ┌───────────────────────────────┐
   │ Loop i = 1 to n               │
   │  Input outstanding            │
   │  Input overdue (1/0)          │
   │  Add to total_outstanding     │
   │  If overdue==1 count++        │
   └────────────────┬──────────────┘
                    ▼
       ┌──────────────────────────┐
       │ delinquency_rate =       │
       │ (count/n)*100            │
       └──────────┬───────────────┘
                  ▼
       ┌──────────────────────────┐
       │ Print total + rate       │
       └──────────┬───────────────┘
                  ▼
        ┌─────────────────────────┐
        │           End           │
        └─────────────────────────┘

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________


















