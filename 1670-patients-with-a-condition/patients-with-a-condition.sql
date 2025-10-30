# Write your MySQL query statement below
-- SELECT patient_id,
-- patient_name,
-- conditions
-- From patients
-- Where conditions like 'DIAB1%'
--     OR  conditions Like '%DIAB1%';


# Write your MySQL query statement below
SELECT 
    patient_id,
    patient_name,
    conditions
FROM Patients
WHERE conditions REGEXP '(^| )DIAB1';
