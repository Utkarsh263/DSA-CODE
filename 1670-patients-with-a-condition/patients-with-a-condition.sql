# Write your MySQL query statement below

SELECT patient_id , 
        patient_name, 
        conditions 
From Patients 
where conditions REGEXP '^DIAB1|\\sDIAB1';