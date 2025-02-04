# Changes
+ `--mode gen --input <input_file> --output <output_file>` generates a 3d hair
  model into `<output_file>` based on `<input_file>`.
+ `--mode demo` now saves the generated `obj` file to `test.obj` in the working
  directory. This should become a separate mode.

# HairNet
Reimplement of [HairNet](https://arxiv.org/abs/1806.07467) (a simple vision)

### Data
I use hair model from [USC-HairSalon](http://www-scf.usc.edu/~liwenhu/SHM/database.html) as row data. The data pre-processing code can be found in [data](https://github.com/pielet/HairNet/blob/master/data), the processed data and pre-trained model can be downloaded from [BaiduYun](https://pan.baidu.com/s/1V09HougFM8Cnv8evB22u7w).

### Network
The network is implemented by Tensorflow. Due to limited time, I ignore the collision loss mentioned in the original paper.


More details can be founded in my report.
