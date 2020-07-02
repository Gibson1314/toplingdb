//
// Created by leipeng on 2020/7/2.
//
#pragma once

#include "json_fwd.h"
#include "rocksdb/rocksdb_namespace.h"
#include "rocksdb/status.h"

namespace ROCKSDB_NAMESPACE {

struct Options;
struct DBOptions;
struct ColumnFamilyOptions;

class Cache;
class CompactionFilterFactory;
class Comparator;
class ConcurrentTaskLimiter;
class Env;
class EventListener;
class FileChecksumGenFactory;
class FilterPolicy;
class FlushBlockPolicyFactory;
class Logger;
class MemTableRepFactory;
class MergeOperator;
class PersistentCache;
class RateLimiter;
class SliceTransform;
class SstFileManager;
class Statistics;
class TableFactory;
class TablePropertiesCollectorFactory;

class JsonOptionsRepo {
 public:
  JsonOptionsRepo() noexcept;
  ~JsonOptionsRepo();
  JsonOptionsRepo(const JsonOptionsRepo&) noexcept;
  JsonOptionsRepo(JsonOptionsRepo&&) noexcept;
  JsonOptionsRepo& operator=(const JsonOptionsRepo&) noexcept;
  JsonOptionsRepo& operator=(JsonOptionsRepo&&) noexcept;

  Status Import(const std::string& json_str);
  Status Import(const nlohmann::json&);
  Status Export(nlohmann::json*) const;
  Status Export(std::string*, bool pretty = false) const;

  ///@{
  /// the semantic is overwrite
  void Add(const std::string& name, const std::shared_ptr<Options>&);
  void Add(const std::string& name, const std::shared_ptr<DBOptions>&);
  void Add(const std::string& name, const std::shared_ptr<ColumnFamilyOptions>&);

  void Add(const std::string& name, const std::shared_ptr<Cache>&);
  void Add(const std::string& name, const std::shared_ptr<CompactionFilterFactory>&);
  void Add(const std::string& name, const Comparator*);
  void Add(const std::string& name, const std::shared_ptr<ConcurrentTaskLimiter>&);
  void Add(const std::string& name, Env*);
  void Add(const std::string& name, const std::shared_ptr<EventListener>&);
  void Add(const std::string& name, const std::shared_ptr<FileChecksumGenFactory>&);
  void Add(const std::string& name, const std::shared_ptr<FilterPolicy>&);
  void Add(const std::string& name, const std::shared_ptr<FlushBlockPolicyFactory>&);
  void Add(const std::string& name, const std::shared_ptr<Logger>&);
  void Add(const std::string& name, const std::shared_ptr<MemTableRepFactory>&);
  void Add(const std::string& name, const std::shared_ptr<MergeOperator>&);
  void Add(const std::string& name, const std::shared_ptr<PersistentCache>&);
  void Add(const std::string& name, const std::shared_ptr<RateLimiter>&);
  void Add(const std::string& name, const std::shared_ptr<SliceTransform>&);
  void Add(const std::string& name, const std::shared_ptr<SstFileManager>&);
  void Add(const std::string& name, const std::shared_ptr<Statistics>&);
  void Add(const std::string& name, const std::shared_ptr<TableFactory>&);
  void Add(const std::string& name, const std::shared_ptr<TablePropertiesCollectorFactory>&);
  ///@}

  bool Get(const std::string& name, std::shared_ptr<Options>*) const;
  bool Get(const std::string& name, std::shared_ptr<DBOptions>*) const;
  bool Get(const std::string& name, std::shared_ptr<ColumnFamilyOptions>*) const;

  bool Get(const std::string& name, std::shared_ptr<Cache>*) const;
  bool Get(const std::string& name, std::shared_ptr<CompactionFilterFactory>*) const;
  bool Get(const std::string& name, const Comparator**) const;
  bool Get(const std::string& name, std::shared_ptr<ConcurrentTaskLimiter>*) const;
  bool Get(const std::string& name, Env**) const;
  bool Get(const std::string& name, std::shared_ptr<EventListener>*) const;
  bool Get(const std::string& name, std::shared_ptr<FileChecksumGenFactory>*) const;
  bool Get(const std::string& name, std::shared_ptr<FilterPolicy>*) const;
  bool Get(const std::string& name, std::shared_ptr<FlushBlockPolicyFactory>*) const;
  bool Get(const std::string& name, std::shared_ptr<Logger>*) const;
  bool Get(const std::string& name, std::shared_ptr<MemTableRepFactory>*) const;
  bool Get(const std::string& name, std::shared_ptr<MergeOperator>*) const;
  bool Get(const std::string& name, std::shared_ptr<PersistentCache>*) const;
  bool Get(const std::string& name, std::shared_ptr<RateLimiter>*) const;
  bool Get(const std::string& name, std::shared_ptr<SliceTransform>*) const;
  bool Get(const std::string& name, std::shared_ptr<SstFileManager>*) const;
  bool Get(const std::string& name, std::shared_ptr<Statistics>*) const;
  bool Get(const std::string& name, std::shared_ptr<TableFactory>*) const;
  bool Get(const std::string& name, std::shared_ptr<TablePropertiesCollectorFactory>*) const;

 protected:
  struct Impl;
  std::shared_ptr<Impl> m_impl;
};

}  // namespace ROCKSDB_NAMESPACE
