function [recognizedCells, partialCells, unrecognizedCells] = ProcessCells(_detectedNumCells, _detectionColumnNum)
  numOfRows = rows(_detectedNumCells);
  curRecognizedRow = 1;
  curPartialRow = 1;
  curUnrecognizedRow = 1;
  recognizedCells = {"";};
  partialCells = {"";};
  unrecognizedCells ={"";};
  
  for curRow = 1:numOfRows
    curDetectionStatus = str2num(char(_detectedNumCells(curRow, _detectionColumnNum)));
    switch curDetectionStatus
      case {-1}
        unrecognizedCells(curUnrecognizedRow, 1:_detectionColumnNum) = _detectedNumCells(curRow, 1:_detectionColumnNum);
        ++curUnrecognizedRow;
      case {0}
        partialCells(curPartialRow, 1:_detectionColumnNum) = _detectedNumCells(curRow, 1:_detectionColumnNum);
        ++curPartialRow;
      otherwise
        recognizedCells(curRecognizedRow, 1:_detectionColumnNum) = _detectedNumCells(curRow, 1:_detectionColumnNum);
        ++curRecognizedRow;
    endswitch
  endfor
  
%  isRecognizedVar = isvarname(recognizedCells);
%  isPartialVar = isvarname(partialCells);
%  isUnrecognizedVar = isvarname(unrecognizedCells);
  
endfunction