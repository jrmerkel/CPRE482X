	??9?2?@??9?2?@!??9?2?@	?&Ug?cm??&Ug?cm?!?&Ug?cm?"e
=type.googleapis.com/tensorflow.profiler.PerGenericStepDetails$??9?2?@??Po??A?6????@Ygs?69??*	^?I+C@2F
Iterator::Modelkׄ?Ơ??!      Y@)???p<???1?????qV@:Preprocessing2R
Iterator::Model::FromTensor??Rp?!&ʱ??p$@)??Rp?1&ʱ??p$@:Preprocessing:?
]Enqueuing data: you may want to combine small input data chunks into fewer but larger chunks.
?Data preprocessing: you may increase num_parallel_calls in <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#map" target="_blank">Dataset map()</a> or preprocess the data OFFLINE.
?Reading data from files in advance: you may tune parameters in the following tf.data API (<a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#prefetch" target="_blank">prefetch size</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#interleave" target="_blank">interleave cycle_length</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/TFRecordDataset#class_tfrecorddataset" target="_blank">reader buffer_size</a>)
?Reading data from files on demand: you should read data IN ADVANCE using the following tf.data API (<a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#prefetch" target="_blank">prefetch</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/Dataset#interleave" target="_blank">interleave</a>, <a href="https://www.tensorflow.org/api_docs/python/tf/data/TFRecordDataset#class_tfrecorddataset" target="_blank">reader buffer</a>)
?Other data reading or processing: you may consider using the <a href="https://www.tensorflow.org/programmers_guide/datasets" target="_blank">tf.data API</a> (if you are not using it now)?
:type.googleapis.com/tensorflow.profiler.BottleneckAnalysis?
device?Your program is NOT input-bound because only 0.0% of the total step time sampled is waiting for input. Therefore, you should focus on reducing other time.no*no9?&Ug?cm?IV1?8??X@Zno#You may skip the rest of this page.B?
@type.googleapis.com/tensorflow.profiler.GenericStepTimeBreakdown?
	??Po????Po??!??Po??      ??!       "      ??!       *      ??!       2	?6????@?6????@!?6????@:      ??!       B      ??!       J	gs?69??gs?69??!gs?69??R      ??!       Z	gs?69??gs?69??!gs?69??b      ??!       JCPU_ONLYY?&Ug?cm?b qV1?8??X@