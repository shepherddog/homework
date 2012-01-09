delimiter $$

CREATE DEFINER=`root`@`localhost` PROCEDURE `test_insert`(iNum MEDIUMINT )
BEGIN
     DECLARE iFlag TINYINT DEFAULT 0;
     WHILE iNum>0
     DO
        IF iFlag=0 THEN
          START TRANSACTION;
        END IF;
        INSERT INTO test(col1,col2,col3)
        VALUES(getname(),ran_string(),floor(1+rand()*20));
        SET iFlag=iFlag+1;
        IF iFlag=100 THEN
           COMMIT;
           SET iFlag=0;
        END IF;
        SET iNum=iNum-1;
    END WHILE;
END$$

