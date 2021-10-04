set base_dir=%cd%\..
set anaconda_path=%base_dir%\env\anaconda3
call %anaconda_path%\Scripts\activate.bat lab2_exp
call %anaconda_path%\Scripts\jupyter.exe notebook  --allow-root -y --notebook-dir %cd%\..\..\..
cmd /k